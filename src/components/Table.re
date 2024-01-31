open Board;

let style =
  ReactDOMStyle.make(
    ~width=string_of_int(60 * 3) ++ "px",
    ~height=string_of_int(60 * 3) ++ "px",
    ~display="grid",
    ~gridTemplateColumns="1fr 1fr 1fr",
    ~gridTemplateRows="1fr 1fr 1fr",
    (),
  );

[@react.component]
let make = () => {
  let (turn, setTurn) = React.useState(() => Some(X));
  let (board, setBoard) = React.useState(() => init());

  let status = board->isWon(turn);

  let handleClick = (index, _) =>
    switch (board->isNotEmptyAt(index) || board->isWon(turn)) {
    | true => ()
    | _ =>
      let nextBoard = board->update(index, turn);
      setBoard(_ => nextBoard);
      nextBoard->isWon(turn) ? () : setTurn(flipTurn);
    };

  <>
    <p> {Printf.sprintf("Next player: %s", turn->toString)->React.string} </p>
    <div style>
      {board
       ->Belt.Array.mapWithIndex((i, s) =>
           <Square
             key={string_of_int(i)}
             onClick={handleClick(i)}
             value={s->toString}
           />
         )
       ->React.array}
    </div>
    <p>
      {status
         ? Printf.sprintf("Winner: %s!", turn->toString)->React.string
         : React.null}
    </p>
  </>;
};
