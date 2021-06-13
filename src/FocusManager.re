module Value =
  Value.Make({
    type t = bool;
  });

type param = {
  focused: bool,
  blur: unit => unit,
  tabIndex: int,
  onBlur: ReactEvent.Focus.t => unit,
  onFocus: ReactEvent.Focus.t => unit,
  onMouseDown: ReactEvent.Mouse.t => unit,
  onMouseUp: ReactEvent.Mouse.t => unit,
};

[@react.component]
let make = (~onChange=?, ~children) => {
  let canBlur = ref(true);
  <Value initial=false ?onChange>
    ...{({value, set}:Value.param) =>
      children({
        focused: value,
        blur: () =>
          if (value == true) {
            %bs.raw
            {| document.activeElement.blur() |};
          },
        tabIndex: (-1),
        onBlur: _ =>
          if (canBlur^) {
            set(_ => false);
          },
        onFocus: _ => set(_ => true),
        onMouseDown: _ => canBlur := false,
        onMouseUp: _ => canBlur := true,
      })
    }
  </Value>;
};
