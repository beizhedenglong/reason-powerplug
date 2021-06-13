let component = ReasonReact.statelessComponent("Active");

module Value =
  Value.Make({
    type t = bool;
  });
type param = {
  active: bool,
  onMouseDown: ReactEvent.Mouse.t => unit,
  onMouseUp: ReactEvent.Mouse.t => unit,
};
let make = (~onChange=?, children) => {
  ...component,
  render: _self =>
    <Value initial=false ?onChange>
      ...(
           ({value, set}) =>
             children({
               active: value,
               onMouseDown: _ => set(_ => true),
               onMouseUp: _ => set(_ => false),
             })
         )
    </Value>,
};
