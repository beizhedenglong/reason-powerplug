open Utils;
module Number =
  Value.Make({
    type t = int;
  });

module StringList = ReList.Make(String);

module StringSet = ReSet.Make(String);

let ignore = (fn, x, _) => fn(x);
ReactDOMRe.renderToElementWithId(
  <div>
    <Value2 initial=2> ...{({value}) => ReasonReact.string(value)} </Value2>
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
               <button onClick={ignore(set, false)}>
                 {ReasonReact.string("set false")}
               </button>
             </div>
         }
    </Toggle>
    <StringList initial=["d", "c", "a", "e", "b", "h", "g"]>
      ...{
           ({list, sort, reset}) =>
             <div>
               <button onClick={ignore(sort, String.compare)}>
                 {ReasonReact.string("sort")}
               </button>
               <button onClick={ignore(reset, ())}>
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