{ pkgs ? import <nixpkgs> {} }:

with pkgs;

stdenv.mkDerivation {
  name = "eva";

  buildInputs = [ gcc boost170.dev boost170.out cmake git ];
}
