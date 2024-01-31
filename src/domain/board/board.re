type turn =
  | X
  | O;

type t = array(option(turn));

let init = () => Array.make(9, None);

let toString =
  fun
  | Some(X) => "X"
  | Some(O) => "O"
  | None => "";

let flipTurn =
  fun
  | Some(X) => Some(O)
  | Some(O) => Some(X)
  | None => None;

let isNotEmptyAt = (board, i) => board[i]->Belt.Option.isSome;

let update = (board, pos, turn) =>
  board->Belt.Array.mapWithIndex((i, x) => i == pos ? turn : x);

let won = [|
  (0, 1, 2),
  (3, 4, 5),
  (6, 7, 8),
  (0, 3, 6),
  (1, 4, 7),
  (2, 5, 8),
  (0, 4, 8),
  (2, 4, 6),
|];

// detect winner pattern in matrix
let isWon = (board, turn) => {
  won
  ->Belt.Array.map(row => {
      let (c1, c2, c3) = row;
      [|c1, c2, c3|]->Belt.Array.every(c => board[c] == turn);
    })
  ->Belt.Array.some(Fun.id);
};
