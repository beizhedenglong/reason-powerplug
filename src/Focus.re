let component = ReasonReact.statelessComponent("Focus");

module Value =
  Value.Make({
    type t = bool;
  });

type param = {
  focused: bool,
  onFocus: ReactEvent.Focus.t => unit,
  onBlur: ReactEvent.Focus.t => unit,
};

let make = (~onChange=?, children) => {
  ...component,
  render: _self =>
    <Value initial=false ?onChange>
      ...(
           ({value, set}) =>
             children({
               focused: value,
               onFocus: _ => set(_ => true),
               onBlur: _ => set(_ => false),
             })
         )
    </Value>,
};
