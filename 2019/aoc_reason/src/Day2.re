/* 3790689 */

type program = {
  mutable input: array(int),
  ip: int,
};

let fetchValue = (input, ix) => input[ix];

let getOpcode = program => program.input[program.ip];
let fetchOpInputs = program => {
  let ip = program.ip;
  let v1i = fetchValue(program.input, ip + 1);
  let v2i = fetchValue(program.input, ip + 2);

  (program.input[v1i], program.input[v2i]);
};

let fetchOpCodeLocation = program =>
  fetchValue(program.input, program.ip + 3);

let setProgramLocationValue = (program, location, value) => {
  program.input[location] = value;
};

let nextOpCode = program => {...program, ip: program.ip + 4};

let rec runProgram = program =>
  switch (getOpcode(program)) {
  | 99 => program
  | 1 =>
    let (v1, v2) = fetchOpInputs(program);
    let location = fetchOpCodeLocation(program);
    let value = v1 + v2;
    setProgramLocationValue(program, location, value);

    program |> nextOpCode |> runProgram;
  | 2 =>
    let (v1, v2) = fetchOpInputs(program);
    let location = fetchOpCodeLocation(program);
    let value = v1 * v2;
    setProgramLocationValue(program, location, value);

    program |> nextOpCode |> runProgram;
  | _ =>
    Js.log("makes no sense");
    program;
  };

let stringToInt = str =>
  switch (Belt.Int.fromString(str)) {
  | Some(i) => i
  | None => 0
  };

let input =
  `utf8
  |> Node_fs.readFileSync("../inputs/day2.txt")
  |> Js.String.split(",")
  |> Array.map(stringToInt);

let myProgram = {input, ip: 0};

myProgram |> runProgram;

myProgram.input[0] |> Js.log;