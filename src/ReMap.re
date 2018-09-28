open Utils.Infix;

module type S = {
  type t;
  let compare: (t, t) => int;
  type value;
};

module Make = (M: S) => {
  module MMap = Map.Make(M);
  include MMap;
  type map = MMap.t(M.value);
  module Value =
    Value.Make({
      type t = map;
    });

  type param = {
    values: map,
    clear: unit => unit,
    reset: unit => unit,
    set: (map => map) => unit,
    get: M.t => option(M.value),
    has: M.t => bool,
    remove: M.t => unit,
    add: (M.t, M.value) => unit,
  };
  let component = ReasonReact.statelessComponent("ReMap");
  let make = (~initial=MMap.empty, ~onChange=?, children) => {
    ...component,
    render: _self =>
      <Value initial ?onChange>
        ...{
             ({value, set, reset}) =>
               children({
                 values: value,
                 clear: () => set(_ => MMap.empty),
                 reset,
                 get: key => (() => MMap.find(key, value)) |> Utils.tryWith,
                 has: Utils.flip(MMap.mem, value),
                 remove: set <|| MMap.remove,
                 set,
                 add: (k, v) => MMap.add(k, v) |> set,
               })
           }
      </Value>,
  };
};