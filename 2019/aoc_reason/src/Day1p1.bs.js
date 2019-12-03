// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Fs = require("fs");
var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Js_math = require("bs-platform/lib/js/js_math.js");
var Caml_format = require("bs-platform/lib/js/caml_format.js");

function isNotempty(str) {
  return str !== "";
}

function calcFuel(mass) {
  return Js_math.floor(mass / 3.0) - 2 | 0;
}

function add(n1, n2) {
  return n1 + n2 | 0;
}

function calcTotalFuel(total, mass) {
  return total + calcFuel(mass) | 0;
}

console.log(List.fold_left(calcTotalFuel, 0, List.map(Caml_format.caml_int_of_string, List.filter(isNotempty)($$Array.to_list(Fs.readFileSync("../inputs/day1.txt", "utf8").split("\n"))))));

exports.isNotempty = isNotempty;
exports.calcFuel = calcFuel;
exports.add = add;
exports.calcTotalFuel = calcTotalFuel;
/*  Not a pure module */
