let component = ReasonReact.statelessComponent("Input");

module Value = Value.Make(String);

type param = {
  value: string,
  reset: unit => unit,
  set: (string => string) => unit,
  onChange: ReactEvent.Form.t => unit,
};

let make = (~initial="", ~onChange=?, children) => {
  ...component,
  render: _self =>
    <Value initial ?onChange>
      ...{
           ({value, set, reset}) =>
             children({
               value,
               reset,
               set,
               onChange: e => {
                 let newValue = e->ReactEvent.Form.target##value;
                 set(_ => newValue);
               },
             })
         }
    </Value>,
};