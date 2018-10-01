let component = ReasonReact.statelessComponent("Hover");

module Value =
  Value.Make({
    type t = bool;
  });

type param = {
  hovered: bool,
  onMouseEnter: ReactEvent.Mouse.t => unit,
  onMouseLeave: ReactEvent.Mouse.t => unit,
};
let make = (~onChange=?, children) => {
  ...component,
  render: _self =>
    <Value initial=false ?onChange>
      ...{
           ({value, set}) =>
             children({
               hovered: value,
               onMouseEnter: _ => set(_ => true),
               onMouseLeave: _ => set(_ => false),
             })
         }
    </Value>,
};