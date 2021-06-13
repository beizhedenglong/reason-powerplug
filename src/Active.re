module Value =
  Value.Make({
    type t = bool;
  });
type param = {
  active: bool,
  onMouseDown: ReactEvent.Mouse.t => unit,
  onMouseUp: ReactEvent.Mouse.t => unit,
};
[@react.component]
let make = (~onChange=?, ~children) => {
  <Value initial=false ?onChange>
    ...{({value, set}:Value.param) =>
      children({
        active: value,
        onMouseDown: _ => set(_ => true),
        onMouseUp: _ => set(_ => false),
      })
    }
  </Value>;
};
