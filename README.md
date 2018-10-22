# Reason PowerPlug
Reason PowerPlug is a set of reuseable `components` and `functors` for  ReasonReact.
This project is inspired by [react-powerplug](https://github.com/renatorib/react-powerplug). 


```ocaml
module StringList = ReList.Make(String);

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
```
[More Examples](https://github.com/beizhedenglong/reason-powerplug/blob/master/examples/Index.re)

## Installation
`yarn add reason-powerplug` or `npm install reason-powerplug --save`

then add `reason-powerplug` to `bs-dependencies` in `bsconfig.json`.

## Components/Functors

All components and functors base on `Value.Make` Functor.

| Name                         | Type                                                                                                  | Component Props         | Render Props                                                           |
| ---------------------------- | ----------------------------------------------------------------------------------------------------- | ----------------------- | ---------------------------------------------------------------------- |
| <h6>STATE CONTAINERS</h6>    |                                                                                                       |
| **Toggle**                   | Component                                                                                             | `{ initial, onChange }` | `{ on, toggle, set, reset }`                                           |
| **Counter**                  | Component                                                                                             | `{ initial, onChange }` | `{ count, inc, dec, incBy, decBy, set, reset }`                        |
| **Value**                    | Functor Value.Make(M:S)<br />`module type S = {type t;};`                                             | `{ initial, onChange }` | `{ value, set, reset }`                                                |
| **ReMap**                    | Functor ReMap.Make(M:S)<br />`module type S = {<br />type t;let compare: (t, t) => int;type value;};` | `{ initial, onChange }` | `{ values, clear, get, has, remove, add, set, reset }`                 |
| **ReSet**                    | Functor ReSet.Make(M:S)<br />`module type S = {<br />type t;let compare: (t, t) => int;};`            | `{ initial, onChange }` | `{ values, add, clear, remove, has, set, reset }`                      |
| **ReList**                   | Functor ReList.Make(M:S)<br />`module type S = {type t;};`                                            | `{ initial, onChange }` | `{ list, first, last, push, pull, sort, set, reset }`                  |
| <h6>FEEDBACK CONTAINERS</h6> |                                                                                                       |
| **Hover**                    | Component                                                                                             | `{ onChange }`          | `{ hovered, onMouseEnter, onMouseLeave }`                              |
| **Active**                   | Component                                                                                             | `{ onChange }`          | `{ active, onMouseDown, onMouseUp }`                                   |
| **Focus**                    | Component                                                                                             | `{ onChange }`          | `{ focused, onFocus, onBlur }`                                         |
| **Touch**                    | Component                                                                                             | `{ onChange }`          | `{ touched, onTouchStart, onTouchEnd }`                                |
| **FocusManager**             | Component                                                                                             | `{ onChange }`          | `{ focused, blur, tabIndex, onBlur, onFocus, onMouseDown, onMouseUp }` |
| <h6>FORM CONTAINERS</h6>     |                                                                                                       |
| **Input**                    | Component                                                                                             | `{ initial, onChange }` | `{value, onChange, set, reset, }`                                      |
| <h6>OTHER</h6>               |                                                                                                       |
| **Interval**                 | Component                                                                                             | `{ delay }`             | `{ stop, start, toggle }`                                              |



### Value

```ocaml
module Number =
  Value.Make({
    type t = int;
  });

<Number initial=1>
  ...{
       ({value, set}) =>
         <div onClick={_ => set(value => value + 1)}>
           {value |> string_of_int |> ReasonReact.string}
         </div>
     }
</Number>


```



TODO
