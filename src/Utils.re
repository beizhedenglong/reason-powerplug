let tryWith = f =>
  try(Some(f())) {
  | _ => None
  };

let compose = (f, g, x) => f(g(x));

let flip = (f, a, b) => f(b, a);

module Infix = {
  let (<||) = compose;
};

include Infix;
