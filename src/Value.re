module type S = {type t;};

module Make = (M: S) => {
  type action =
    | Set(M.t => M.t);

  type param = {
    value: M.t,
    set: (M.t => M.t) => unit,
    reset: unit => unit,
  };
  // the updater type used below is the param type aliased as updater
  // type updater = param;
  [@react.component]
  let make = (~initial, ~onChange=_value => (), ~children) => {
    let (state, dispatch) =
      React.useReducer(
        (state, action) =>
          switch (action) {
          | Set(updater) => updater(state)
          },
        initial,
      );

    children({
      value: state,
      set: updater => dispatch(Set(updater)),
      reset: () => onChange(initial),
    });
  };
};
