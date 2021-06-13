module Value =
  Value.Make({
    type t = bool;
  });

type param = {
  hovered: bool,
  onMouseEnter: ReactEvent.Mouse.t => unit,
  onMouseLeave: ReactEvent.Mouse.t => unit,
};
[@react.component]
let make = (~onChange=?, ~children) => {
  <Value initial=false ?onChange>
    ...{({value, set}:Value.param) =>
      children({
        hovered: value,
        onMouseEnter: _ => set(_ => true),
        onMouseLeave: _ => set(_ => false),
      })
    }
  </Value>;
};
