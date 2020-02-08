int main(int argc, char **argv) {
  eva::Engine engine;
  eva::HttpEngine http(engine);

  eva::DummySource dummy(engine);

  dummy.start();

  http.start();
  engine.start();

  eva::Stream stream(dummy.mockSource("AAPL"));

  http.addToBoard(stream);

  engine.wait();

  return 0;
}
