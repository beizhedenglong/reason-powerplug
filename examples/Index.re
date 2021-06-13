open Utils;
module Number =
  Value.Make({
    type t = int;
  });

module StringList = ReList.Make(String);

module StringSet = ReSet.Make(String);

module Value =
  Value.Make({
    type t = int;
  });

let ignore = (fn, x, _) => fn(x);
ReactDOMRe.renderToElementWithId(
  <div>
    <h1> {React.string("Input Functor")} </h1>
    <Input>
      ...{({value, onChange}: Input.param) => {
        Js.log2("value: ", value);
        <div>
          <p> {React.string("open the console to see changes")} </p>
          <input value onChange />
        </div>;
      }}
    </Input>
    <h1> {React.string("Value Functor")} </h1>
    <Value initial=1>
      ...{({value, set, reset}: Value.param) =>
        <div>
          <button onClick={ignore(set, _ => 100)}>
            {React.string("set 1000")}
          </button>
          <Interval delay=value>
            ...{({stop, start}: Interval.param) =>
              <div>
                <button onClick={ignore(start, ())}>
                  {React.string("start")}
                </button>
                <button onClick={ignore(stop, ())}>
                  {React.string("stop")}
                </button>
                <button onClick={ignore(reset, ())}>
                  {React.string("reset")}
                </button>
                {Js.Date.now() |> Js.Float.toString |> React.string}
              </div>
            }
          </Interval>
        </div>
      }
    </Value>
    <h1> {React.string("Hover Functor")} </h1>
    <Hover>
      ...{({hovered, onMouseEnter, onMouseLeave}: Hover.param) =>
        <div onMouseEnter onMouseLeave>
          {React.string(
             " You are "
             ++ (hovered ? "hovering" : "not hovering")
             ++ "this div",
           )}
        </div>
      }
    </Hover>
    <h1> {React.string("StringSet")} </h1>
    <StringSet initial={StringSet.of_list(["1", "2", "3"])}>
      ...{({values, add, clear}: StringSet.param) =>
        <div>
          <button onClick={ignore(add, "4")}>
            {React.string("add 4")}
          </button>
          <button onClick={ignore(clear, ())}>
            {React.string("clear")}
          </button>
          <ul>
            {values
             |> StringSet.elements
             |> List.map(item => <li key=item> {React.string(item)} </li>)
             |> Array.of_list
             |> React.array}
          </ul>
        </div>
      }
    </StringSet>
    <h1> {React.string("Number")} </h1>
    <Number initial=1>
      ...{({value, set}: Number.param) =>
        <div onClick={_ => set(value => value + 1)}>
          {value |> string_of_int |> React.string}
        </div>
      }
    </Number>
    <h1> {React.string("Counter")} </h1>
    <Counter initial=0 onChange={count => Js.log(count)}>
      ...{({count, inc}: Counter.param) =>
        <div>
          {count |> string_of_int |> React.string}
          <button onClick={_ => inc()}> {React.string("+1")} </button>
        </div>
      }
    </Counter>
    <h1> {React.string("Toggle")} </h1>
    <Toggle initial=true onChange={Js.log <|| string_of_bool}>
      ...{({on, toggle, set}: Toggle.param) =>
        <div>
          <button onClick={ignore(toggle, ())}>
            {React.string("toggle")}
          </button>
          <button onClick={ignore(set, _ => false)}>
            {React.string("set false")}
          </button>
          <div>
            {on
               ? {
                 React.string("toggle show");
               }
               : React.null}
          </div>
        </div>
      }
    </Toggle>
    <h1> {React.string("StringList")} </h1>
    <StringList initial=["d", "c", "a", "e", "b", "h", "g"]>
      ...{({list, sort, reset}: StringList.param) =>
        <div>
          <button onClick={_ => sort(String.compare)}>
            {React.string("sort")}
          </button>
          <button onClick={_ => reset()}> {React.string("reset")} </button>
          <ul>
            {list
             |> List.map(s => <li key=s> {React.string(s)} </li>)
             |> Array.of_list
             |> React.array}
          </ul>
        </div>
      }
    </StringList>
  </div>,
  "app",
);
