[@decco] type dimensions = { width: int, height: int };

let make:
    {.  "children": Js.Json.t => React.element,
        "className": option(string), "ref": option(ReactDOMRe.domRef)
    } => React.element;
let makeProps:
    (   ~ref: ReactDOMRe.domRef=?, ~className: string=?,
        ~children: dimensions => React.element, unit) =>
    {. "children": Js.Json.t => React.element,
      "className": option(string), "ref": option(ReactDOMRe.domRef) };
