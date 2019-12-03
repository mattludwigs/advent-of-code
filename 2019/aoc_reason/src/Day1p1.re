/* 327199*/

let isNotempty = str =>
  if (str == "") {
    false;
  } else {
    true;
  };

let calcFuel = mass => Js.Math.floor(mass /. 3.0) - 2;

let add = (n1, n2) => n1 + n2;

let calcTotalFuel = (total, mass) =>
  mass |> float_of_int |> calcFuel |> add(total);

`utf8
|> Node_fs.readFileSync("../inputs/day1.txt")
|> Js.String.split("\n")
|> Array.to_list
|> List.filter(isNotempty)
|> List.map(int_of_string)
|> List.fold_left(calcTotalFuel, 0)
|> Js.log;