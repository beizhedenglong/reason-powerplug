module type S = {type t;};

module Make = (M: S) => {
  type action =
    | Set(M.t => M.t);

  let component = ReasonReact.reducerComponent("Value");

  type param = {
    value: M.t,
    set: (M.t => M.t) => unit,
    reset: unit => unit,
  };

  let make = (~initial, ~onChange=_value => (), children) => {
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
};
