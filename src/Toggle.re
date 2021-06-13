module Value =
  Value.Make({
    type t = bool;
  });

let component = ReasonReact.statelessComponent("Toggle");
type param = {
  on: bool,
  toggle: unit => unit,
  set: (bool => bool) => unit,
  reset: unit => unit,
};
let make = (~initial=false, ~onChange=?, children) => {
  ...component,
  render: _self =>
    <Value initial ?onChange>
      ...(
           ({value, set, reset}) =>
             children({
               on: value,
               toggle: () => set(value => !value),
               set,
               reset,
             })
         )
    </Value>,
};
