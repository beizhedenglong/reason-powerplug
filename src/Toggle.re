module Value =
  Value.Make({
    type t = bool;
  });

type param = {
  on: bool,
  toggle: unit => unit,
  set: (bool => bool) => unit,
  reset: unit => unit,
};
[@react.component]
let make = (~initial=false, ~onChange=?, ~children) => {
  <Value initial ?onChange>
    ...{({value, set, reset}:Value.param) =>
      children({on: value, toggle: () => set(value => !value), set, reset})
    }
  </Value>;
};
