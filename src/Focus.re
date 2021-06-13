module Value =
  Value.Make({
    type t = bool;
  });

type param = {
  focused: bool,
  onFocus: ReactEvent.Focus.t => unit,
  onBlur: ReactEvent.Focus.t => unit,
};

[@react.component]
let make = (~onChange=?, ~children) => {
  <Value initial=false ?onChange>
    ...{({value, set}: Value.param) =>
      children({
        focused: value,
        onFocus: _ => set(_ => true),
        onBlur: _ => set(_ => false),
      })
    }
  </Value>;
};
