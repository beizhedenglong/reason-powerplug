module Value =
  Value.Make({
    type t = bool;
  });

let component = ReasonReact.statelessComponent("Toggle");
type param = {
  on: bool,
  toggle: unit => unit,
  set: (bool => bool) => unit,
};
let make = (~initial=false, ~onChange=?, children) => {
  ...component,
  render: _self =>
    <Value initial ?onChange>
      ...{
           ({value, set}) =>
             children({on: value, toggle: () => set(value => !value), set})
         }
    </Value>,
};