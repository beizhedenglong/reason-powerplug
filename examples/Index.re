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
    <Input> ...{({value, onChange}) => <input value onChange />} </Input>
    <Value initial=1>
      ...{
           ({value, set, reset}) =>
             <div>
               <button onClick={ignore(set, _ => 100)}>
                 {ReasonReact.string("set 1000")}
               </button>
               <Interval delay=value>
                 ...{
                      ({stop, start}) =>
                        <div>
                          <button onClick={ignore(start, ())}>
                            {ReasonReact.string("start")}
                          </button>
                          <button onClick={ignore(stop, ())}>
                            {ReasonReact.string("stop")}
                          </button>
                          {
                            Js.Date.now()
                            |> string_of_float
                            |> ReasonReact.string
                          }
                        </div>
                    }
               </Interval>
             </div>
         }
    </Value>
    <Hover>
      ...{
           ({hovered, onMouseEnter, onMouseLeave}) =>
             <div onMouseEnter onMouseLeave>
               {
                 ReasonReact.string(
                   " You are "
                   ++ (hovered ? "hovering" : "not hovering")
                   ++ "this div",
                 )
               }
             </div>
         }
    </Hover>
    <StringSet initial={StringSet.of_list(["1", "2", "3"])}>
      ...{
           ({values, add, clear}) =>
             <div>
               <button onClick={ignore(add, "4")}>
                 {ReasonReact.string("add 4")}
               </button>
               <button onClick={ignore(clear, ())}>
                 {ReasonReact.string("clear")}
               </button>
               <ul>
                 {
                   values
                   |> StringSet.elements
                   |> List.map(item =>
                        <li key=item> {ReasonReact.string(item)} </li>
                      )
                   |> Array.of_list
                   |> ReasonReact.array
                 }
               </ul>
             </div>
         }
    </StringSet>
    <Number initial=1>
      ...{
           ({value, set}) =>
             <div onClick={_ => set(value => value + 1)}>
               {value |> string_of_int |> ReasonReact.string}
             </div>
         }
    </Number>
    <Counter initial=0 onChange={count => Js.log(count)}>
      ...{
           ({count, inc}) =>
             <div>
               {count |> string_of_int |> ReasonReact.string}
               <button onClick={_ => inc()}>
                 {ReasonReact.string("+1")}
               </button>
             </div>
         }
    </Counter>
    <Toggle initial=true onChange={Js.log <|| string_of_bool}>
      ...{
           ({toggle, set}) =>
             <div>
               <button onClick={ignore(toggle, ())}>
                 {ReasonReact.string("toggle")}
               </button>
               <button onClick={ignore(set, _ => false)}>
                 {ReasonReact.string("set false")}
               </button>
             </div>
         }
    </Toggle>
    <StringList initial=["d", "c", "a", "e", "b", "h", "g"]>
      ...{
           ({list, sort, reset}) =>
             <div>
               <button onClick={_ => sort(String.compare)}>
                 {ReasonReact.string("sort")}
               </button>
               <button onClick={_ => reset()}>
                 {ReasonReact.string("reset")}
               </button>
               <ul>
                 {
                   list
                   |> List.map(s => <li key=s> {ReasonReact.string(s)} </li>)
                   |> Array.of_list
                   |> ReasonReact.array
                 }
               </ul>
             </div>
         }
    </StringList>
  </div>,
  "app",
);