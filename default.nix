{ lib, gcc11Stdenv, cmake, conan }
pkgs.gcc11Stdenv.mkDerivation {
  name = "cppDevelopmentEnvironment";
  buildInputs = [
    jetbrains.clion
    # gcc11
    clang-tools
    # clang_11 # if imported here, it overrides gcc, can be used via $GLANG11
    gh
    cmake
    conan
    ccache
    # coverage tools
    lcov # improves default gcov
    gcovr # generates reports
    gsl
    perl # for capnproto build tools
    automake
  ];
  # shellHook = ''
  #   # export LD_LIBRARY_PATH=${pkgs.gcc11.cc.lib}/lib:$LD_LIBRARY_PATH
  # '';
  CLANG11 = clang_11;
}
