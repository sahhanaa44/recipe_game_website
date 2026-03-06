async function loadWasm() {

    const response = await fetch("recipe_game.wasm");
    const bytes = await response.arrayBuffer();

    const wasm = await WebAssembly.instantiate(bytes);

    console.log("WASM Loaded Successfully");

    console.log("update():", wasm.instance.exports.update());
    console.log("render():", wasm.instance.exports.render());
}

loadWasm();
