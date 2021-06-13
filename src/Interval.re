type state = {
  times: int,
  delay: int,
};

type action =
  | Update;

type param = {
  start: unit => unit,
  stop: unit => unit,
  toggle: unit => unit,
};

/* outsiede of make function */
let intervalIdOption = ref(None);

[@react.component]
let make = (~delay=1000, ~children) => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | Update => {...state, times: state.times + 1}
        },
      {times: 0, delay},
    );
  let start = _ =>
    switch (intervalIdOption^) {
    | None =>
      intervalIdOption :=
        Some(Js.Global.setInterval(() => dispatch(Update), state.delay))
    | Some(_) => ()
    };
  let stop = () =>
    switch (intervalIdOption^) {
    | None => ()
    | Some(intervalId) =>
      Js.Global.clearInterval(intervalId);
      intervalIdOption := None;
    };
  let toggle = () =>
    switch (intervalIdOption^) {
    | None => start()
    | Some(_) => stop()
    };
  let stop = () =>
    switch (intervalIdOption^) {
    | None => ()
    | Some(intervalId) =>
      Js.Global.clearInterval(intervalId);
      intervalIdOption := None;
    };

  React.useEffect0(() => {
    start();
    Some(() => stop());
  });
  React.useEffect1(
    () => {
      state.delay != delay ? stop() : start();
      None;
    },
    [|state|],
  );

  children({start, stop, toggle});
};
