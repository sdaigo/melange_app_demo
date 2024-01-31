[@react.component]
let make = (~value, ~onClick) => {
  <button
    onClick
    style={ReactDOMStyle.make(
      ~width="60px",
      ~height="60px",
      ~fontSize="1rem",
      (),
    )}>
    {React.string(value)}
  </button>;
};
