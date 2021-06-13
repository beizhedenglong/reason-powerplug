const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const outputDir = path.join(__dirname, 'build');

const isProd = process.env.NODE_ENV === 'production';

module.exports = {
  entry: './lib/js/examples/Index.bs.js',
  mode: isProd ? 'production' : 'development',
  plugins: [
    new HtmlWebpackPlugin({
      title: 'Reason PowerPlug',
      template: 'examples/index.html'
    })
  ],
  output: {
    filename: '[name].bundle.js',
    path: outputDir,
    clean: true
  }
};
