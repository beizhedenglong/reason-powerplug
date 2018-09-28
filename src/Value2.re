type t;
type action =
  | Set(t => t);

let component = ReasonReact.reducerComponent("Value");

type param = {
  value: t,
  set: (t => t) => unit,
  reset: unit => unit,
};

let make = (~initial: t, ~onChange: t => unit=_value => (), children) => {
  ...component,
  initialState: () => initial,
  reducer: (action, state) =>
    switch (action) {
    | Set(updater) =>
      ReasonReact.UpdateWithSideEffects(
        updater(state),
        (self => onChange(self.state)),
      )
    },
  render: self =>
    children({
      value: self.state,
      set: updater => self.send(Set(updater)),
      reset: () => self.send(Set(_ => initial)),
    }),
};