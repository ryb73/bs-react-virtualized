const path                  = require("path"),
      webpack               = require("webpack");

function rel(relPath) {
    return path.resolve(__dirname, relPath);
}

module.exports = {
    mode: "development",

    entry: {
        index: rel("lib/js/test/index.js"),
    },

    output: {
        path: rel("test/js"),
        filename: "[name].js",
    },

    plugins: [
        new webpack.WatchIgnorePlugin([
            rel("node_modules/"),
        ]),
    ],

    devtool: "source-map",
};
