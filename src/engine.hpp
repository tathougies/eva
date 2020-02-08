#ifndef __eva_engine_H__
#define __eva_engine_H__

#include <boost/posix_time/ptime.hpp>

#include "common.hpp"
#include "type.hpp"

namespace eva {
  class EngineSubmissionImpl;
  class StreamSource;
  class Engine;

  class StreamPtr {
  public:
    StreamPtr(Engine &engine, const StreamId &streamId);
    ~StreamPtr();

    inline StreamId id() const { return m_id; }
    inline Engine &engine() { return m_engine; }

    inline Data data() const { return *m_data; }

    void setData(Data data);

  private:
    Engine &m_engine;
    StreamId m_id;

    /**
     * Current best place to submit data, or we can overwrite the pointer
     */
    Data *m_data;
  };

  /**
   * An interface that allows data to be submitted to an Engine
   */
  class IEngineSubmission {
  public:
    virtual ~IEngineSubmission();

    virtual StreamPtr newStream(interned_string name, const Type &t);
    virtual void signalUpdate(const boost::posix_time::ptime &ts,
                              const StreamPtr &what);
  };

  class StreamSource {
  public:
    StreamSource(Engine &engine, const interned_string &moduleName);
    virtual ~StreamSource();

    inline Engine &engine() { return m_engine; }

    inline interned_string moduleName() const { return m_module; }

  protected:
    IEngineSubmission &submission() { return m_submission; }

    virtual boost::posix_time::time_duration onWillAccept(const boost::posix_time::ptime &ts,
                                                          const StreamSource &from_whom) =0;

  private:
    Engine &m_engine;
    IEngineSubmission &m_submission;

    interned_string m_module;

    friend class Engine;
  };

  /**
   * An engine offers a way to run streams in real time
   */
  class Engine {
  public:
    Engine(Allocator &allocator);
    ~Engine();

    inline Allocator &allocator() { return m_allocator; }

    void start();
    void wait();

    StreamPtr animateStream(_);

    /**
     * Add an engine observer. This will receive every value update in the engine
     */
    void addEngineObserver(const std::shared_ptr<IEngineObserver> &observer);

    /**
     * Remove an engine observer
     */
    void removeEngineObserver(const std::shared_ptr<IEngineObserver> &observer);

  protected:
    IEngineSubmission &registerStreamSource(StreamSource *src);
    void releaseStreamSource(StreamSource *src);

    Allocator &m_allocator;

    boost::mutex m_observersMutex;
    std::hash_set< std::shared_ptr<IEngineObserver> > m_observers;

    eva::BitTrie<512, 4, StreamInfo> m_streams;

    /**
     * The time the last event was accepted. We do not accept any events before this time
     */
    boost::posix_time::ptime m_lastEventAcceptedTime;

    friend class StreamSource;
    friend class EngineSubmissionImpl;
  };
}

#endif
