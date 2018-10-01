type state = {
  times: int,
  delay: int,
};

type action =
  | Update;

let component = ReasonReact.reducerComponent("Interval");

type param = {
  start: unit => unit,
  stop: unit => unit,
  toggle: unit => unit,
};

/* outsiede of make function */
let intervalIdOption = ref(None);

let make = (~delay=1000, children) => {
  let start = (_, self) =>
    switch (intervalIdOption^) {
    | None =>
      intervalIdOption :=
        Some(
          Js.Global.setInterval(
            () => self.ReasonReact.send(Update),
            self.state.delay,
          ),
        )
    | Some(_) => ()
    };
  let stop = () =>
    switch (intervalIdOption^) {
    | None => ()
    | Some(intervalId) =>
      Js.Global.clearInterval(intervalId);
      intervalIdOption := None;
    };
  let toggle = (_, self) =>
    switch (intervalIdOption^) {
    | None => self.ReasonReact.handle(start, ())
    | Some(_) => stop()
    };

  {
    ...component,
    initialState: () => {times: 0, delay},
    didMount: self => self.handle(start, ()),
    willUnmount: _self => stop(),
    willReceiveProps: ({state}) =>
      state.delay != delay ? {...state, delay} : state,
    didUpdate: ({oldSelf, newSelf}) =>
      if (oldSelf.state.delay != newSelf.state.delay) {
        stop();
        newSelf.handle(start, ());
      },
    reducer: (action, state) =>
      switch (action) {
      | Update => ReasonReact.Update({...state, times: state.times + 1})
      },
    render: self =>
      children({
        start: self.handle(start),
        stop,
        toggle: self.handle(toggle),
      }),
  };
};