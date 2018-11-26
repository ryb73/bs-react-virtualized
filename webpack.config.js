const path                  = require("path"),
      webpack               = require("webpack");

function rel(relPath) {
    return path.resolve(__dirname, relPath);
}

function config(subdir, module) {
    return {
        mode: "development",

        entry: {
            index: rel(`lib/js/test/${subdir}/${module}.js`),
        },

        output: {
            path: rel(`test/${subdir}/js`),
            filename: "[name].js",
        },

        module: {
            rules: [{
                test: /\.css$/,
                use: [ "style-loader", "css-loader" ]
            }]
        },

        plugins: [
            new webpack.WatchIgnorePlugin([
                rel("node_modules/"),
            ]),
        ],

        devtool: "source-map",
    };
}

module.exports = [ config("grid", "GridExample"), config("table", "TableExample") ];