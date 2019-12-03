/* 327199*/

let isNotempty = str =>
  if (str == "") {
    false;
  } else {
    true;
  };

let calcFuel = mass =>
  switch (Belt.Int.fromString(mass)) {
  | None => None /* This should never happen */
  | Some(i) =>
    let floatMass = Belt.Int.toFloat(i);
    Some(Js.Math.floor(floatMass /. 3.0) - 2);
  };

let calcTotalFuel = (total, fuel) => fuel + total;

`utf8
|> Node_fs.readFileSync("../inputs/day1.txt")
|> Js.String.split("\n")
|> Array.to_list
|> List.filter(isNotempty)
|> List.map(calcFuel)
|> List.filter(Belt.Option.isSome)
|> List.map(Belt.Option.getExn)
|> List.fold_left(calcTotalFuel, 0)
|> Js.log;