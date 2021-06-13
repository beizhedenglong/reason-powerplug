// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");

function tryWith(f) {
  try {
    return Caml_option.some(Curry._1(f, undefined));
  }
  catch (exn){
    return ;
  }
}

function compose(f, g, x) {
  return Curry._1(f, Curry._1(g, x));
}

function flip(f, a, b) {
  return Curry._2(f, b, a);
}

var Infix = {
  $less$pipe$pipe: compose
};

var $less$pipe$pipe = compose;

exports.tryWith = tryWith;
exports.compose = compose;
exports.flip = flip;
exports.Infix = Infix;
exports.$less$pipe$pipe = $less$pipe$pipe;
/* No side effect */
