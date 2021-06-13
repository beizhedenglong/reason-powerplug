module Value =
  Value.Make({
    type t = bool;
  });

type param = {
  touched: bool,
  onTouchStart: ReactEvent.Touch.t => unit,
  onTouchEnd: ReactEvent.Touch.t => unit,
};

[@react.component]
let make = (~onChange=?, ~children) => {
  <Value initial=false ?onChange>
    ...{({value, set}:Value.param) =>
      children({
        touched: value,
        onTouchStart: _ => set(_ => true),
        onTouchEnd: _ => set(_ => false),
      })
    }
  </Value>;
};
