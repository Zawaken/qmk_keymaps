{
  description = "Zephyr flake from https://github.com/katyo/zephyr-rtos.nix";

  inputs.nixpkgs.url = "nixpkgs/release-23.11";

  inputs.zephyr-rtos = {
    url = "github:katyo/zephyr-rtos.nix";
    inputs.nixpkgs.follows = "nixpkgs";
  };

  outputs = { nixpkgs, zephyr-rtos, ... }:
    let
      supportedSystems = [ "x86_64-linux" "x86_64-darwin" "aarch64-linux" "aarch64-darwin" ];
      forAllSystems = nixpkgs.lib.genAttrs supportedSystems;
      nixpkgsFor = forAllSystems (system: import nixpkgs {
        inherit system;
        overlays = [ zephyr-rtos.overlays.default ];
        packages = [ nixpkgs.python311Packages.west ];
      });
    in
    {
      devShells = forAllSystems (system: {
        default = nixpkgsFor.${system}.mkZephyrSdk { };
      });
    };
}
