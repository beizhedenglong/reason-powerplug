type param = {
  count: int,
  set: (int => int) => unit,
  inc: unit => unit,
  dec: unit => unit,
  incBy: int => unit,
  decBy: int => unit,
  reset: unit => unit,
};
module Value =
  Value.Make({
    type t = int;
  });
[@react.component]
let make = (~initial, ~onChange=?, ~children) => {
  <Value initial ?onChange>
    ...{({value, set, reset}: Value.param) =>
      children({
        count: value,
        set,
        reset,
        inc: () => set(value => value + 1),
        dec: () => set(value => value - 1),
        incBy: number => set(value => value + number),
        decBy: number => set(value => value - number),
      })
    }
  </Value>;
};
