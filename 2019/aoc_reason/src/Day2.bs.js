// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Fs = require("fs");
var $$Array = require("bs-platform/lib/js/array.js");
var Belt_Int = require("bs-platform/lib/js/belt_Int.js");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var Caml_int32 = require("bs-platform/lib/js/caml_int32.js");

var fetchValue = Caml_array.caml_array_get;

function getOpcode(program) {
  return Caml_array.caml_array_get(program[/* input */0], program[/* ip */1]);
}

function fetchOpInputs(program) {
  var ip = program[/* ip */1];
  var v1i = Caml_array.caml_array_get(program[/* input */0], ip + 1 | 0);
  var v2i = Caml_array.caml_array_get(program[/* input */0], ip + 2 | 0);
  return /* tuple */[
          Caml_array.caml_array_get(program[/* input */0], v1i),
          Caml_array.caml_array_get(program[/* input */0], v2i)
        ];
}

function fetchOpCodeLocation(program) {
  return Caml_array.caml_array_get(program[/* input */0], program[/* ip */1] + 3 | 0);
}

function setProgramLocationValue(program, $$location, value) {
  return Caml_array.caml_array_set(program[/* input */0], $$location, value);
}

function nextOpCode(program) {
  return /* record */[
          /* input */program[/* input */0],
          /* ip */program[/* ip */1] + 4 | 0
        ];
}

function runProgram(_program) {
  while(true) {
    var program = _program;
    var match = getOpcode(program);
    var switcher = match - 1 | 0;
    if (switcher === 0 || switcher === 1) {
      if (switcher !== 0) {
        var match$1 = fetchOpInputs(program);
        var $$location = fetchOpCodeLocation(program);
        var value = Caml_int32.imul(match$1[0], match$1[1]);
        setProgramLocationValue(program, $$location, value);
        _program = nextOpCode(program);
        continue ;
      } else {
        var match$2 = fetchOpInputs(program);
        var $$location$1 = fetchOpCodeLocation(program);
        var value$1 = match$2[0] + match$2[1] | 0;
        setProgramLocationValue(program, $$location$1, value$1);
        _program = nextOpCode(program);
        continue ;
      }
    } else if (switcher !== 98) {
      console.log("makes no sense");
      return program;
    } else {
      return program;
    }
  };
}

function stringToInt(str) {
  var match = Belt_Int.fromString(str);
  if (match !== undefined) {
    return match;
  } else {
    return 0;
  }
}

var input = $$Array.map(stringToInt, Fs.readFileSync("../inputs/day2.txt", "utf8").split(","));

var myProgram = /* record */[
  /* input */input,
  /* ip */0
];

runProgram(myProgram);

console.log(Caml_array.caml_array_get(myProgram[/* input */0], 0));

exports.fetchValue = fetchValue;
exports.getOpcode = getOpcode;
exports.fetchOpInputs = fetchOpInputs;
exports.fetchOpCodeLocation = fetchOpCodeLocation;
exports.setProgramLocationValue = setProgramLocationValue;
exports.nextOpCode = nextOpCode;
exports.runProgram = runProgram;
exports.stringToInt = stringToInt;
exports.input = input;
exports.myProgram = myProgram;
/* input Not a pure module */
