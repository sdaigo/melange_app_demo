type t =
  | Empty
  | O
  | X;

let toString =
  fun
  | X => "X"
  | O => "O"
  | Empty => "";

let isNotEmpty = cell => cell != Empty;
