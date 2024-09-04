let
  pkgs = import <nixpkgs> { };

  matplotlib = pkgs.python3Packages.matplotlib.override { enableQt = true; };

in
  pkgs.mkShell {
    buildInputs = [ matplotlib ];

    QT_PLUGIN_PATH = with pkgs.qt5; "${qtbase}/${qtbase.qtPluginPrefix}";
    QT_QPA_PLATFORM = "xcb";

    # shellHook = "./tester.py";
  }
