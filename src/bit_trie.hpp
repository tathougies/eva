#ifndef __eva_bit_trie_H__
#define __eva_bit_trie_H__

namespace eva {
  /**
   * A bit-trie is a trie with keys of a particular bit length.
   *
   * The branching factor is given by the Nibble parameter which
   * specifies the number of bits mapped by each level of the trie.
   */
  template<int Bits, int Nibble, typename T>
  class BitTrie {
  public:
    const int branching_factor = 1 << Nibble;

    BitTrie();
    ~BitTrie() {
      for ( std::size_t i = 0; i < branching_factor; ++i ) {
        if ( m_hasValue[i] ) {
          if ( m_leaves[i] )
            delete m_leaves[i];
          else
            m_branches.deleteAt(i);
        }
      }
    }

    typedef std::array<std::uint8_t, (Bits / 8)> key_type;
    typedef T mapped_type;
    typedef T value_type;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef value_type &reference;
    typedef const value_type &reference;
    typedef value_type *pointer;
    typedef const value_type *const_pointer;

    T &at(const Key &key);

    const T &at(const Key &key) const;

    T &operator[] (const Key &key);

    bool empty() const noexcept {
      return m_hasValue.none();
    }

    std::size_t size() const noexcept {
      std::size_t a = 0;
      for ( std::size_t i = 0; i < branching_factor; ++i ) {
        if ( m_hasValue[i] ) {
          if ( m_leaves[i] )
            a++;
          else
            a += m_branches.sizeAt(i);
        }
      }
      return a;
    }

    std::size_t max_size() const noexcept {
      return (1 << Bits);
    }

    void clear() {
      BitTrie<Bits, Nibble, T> empty_trie;
      swap(empty_trie);
    }

    void swap(BitTrie<Bits, Nibble, T> &other) {
      m_hasValue.swap(other.m_hasValue);
      m_leaves.swap(other.m_leaves);
    }

  private:
    std::bitset<branching_factor> m_hasValue;
    std::array<T *, branching_factor> m_leaves;
    BranchHelper<Bits, Nibble, Nibble < Bits, T>::type, branching_factor> m_branches;
  };

  template <int Bits, int Nibble, bool canBranch, typename T>
  class BranchHelper;

  template<int Bits, int Nibble, typename T>
  class BranchHelper<Bits, Nibble, true, T> {
  public:
    bool branchesAt(std::size_t i) const {
      return m_branches[i] != nullptr;
    }

    std::size_t sizeAt(std::size_t i) const {
      return branchesAt(i) ? m_branch[i]->size() : 0;
    }

    void deleteAt(std::size_t i) const {
      delete m_branches[i];
      m_branches[i] = nullptr;
    }

  private:
    std::array<BitTrie<Bits - Nibble, Nibble, T> *, (1 << Nibble)> m_branches;

  };

  template<int Bits, int Nibble, typename T>
  class BranchHelper<Bits, Nibble, false, T> {
  public:
    bool branchesAt(std::size_t i) const { return false; }
    bool sizeAt(std::size_t i) const { return 0; }
  };
}

#endif
