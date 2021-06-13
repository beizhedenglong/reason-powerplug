let component = ReasonReact.statelessComponent("Touch");

module Value =
  Value.Make({
    type t = bool;
  });

type param = {
  touched: bool,
  onTouchStart: ReactEvent.Touch.t => unit,
  onTouchEnd: ReactEvent.Touch.t => unit,
};

let make = (~onChange=?, children) => {
  ...component,
  render: _self =>
    <Value initial=false ?onChange>
      ...(
           ({value, set}) =>
             children({
               touched: value,
               onTouchStart: _ => set(_ => true),
               onTouchEnd: _ => set(_ => false),
             })
         )
    </Value>,
};
