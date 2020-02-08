#include "engine.hpp"

namespace eva {
  IEngineSubmission::~IEngineSubmission() {
  }

  StreamSource::StreamSource(Engine &engine, const interned_string &moduleName)
    : m_engine(engine),
      m_submission(engine.registerStreamSource(this)),
      m_module(moduleName) {
  }

  StreamSource::~StreamSource() {
  }

  Engine::Engine(Allocator &allocator)
    : m_allocator(allocator) {
  }

  Engine::~Engine() {
  }

  void Engine::addEngineObserver(const std::shared_ptr<IEngineObserver> &observer) {
    boost::upgrade_lock observersLock(m_observersMutex);
    if ( m_observers.find(observer) == m_observers.end() ) {
      boost::upgrade_to_unique_lock observersWriteLock(observersLock);
      m_observers.insert(observer);
    }
  }

  void Engine::removeEngineObserver(const std::shared_ptr<IEngineObserver> &observer) {
    boost::unique_lock observersLock(m_observersMutex);
    auto place(m_observers.find(observer));
    if ( place != m_observers.end() ) {
      m_observers.erase(place)
    }
  }

  IEngineSubmission &Engine::registerStreamSource(StreamSource *src) {
    _
  }

  void Engine::releaseStreamSource(StreamSource *src) {
  }
}
