[@bs.module "react-virtualized"] [@react.component]
external make:
    (   ~ref: ReactDOMRe.domRef=?, ~className: string=?,
        ~children: Js.Json.t => React.element, unit
    ) => React.element = "AutoSizer";

[@bs.deriving abstract]
type jsProps = {
    [@bs.optional] className: string
};

[@decco] type dimensions = { width: int, height: int };

let makeProps = (~ref=?, ~className=?, ~children, ()) =>
    makeProps(
        ~ref?, ~className?,
        ~children=(json) =>
            dimensions_decode(json)
            |> Belt.Result.getExn
            |> children,
        ()
    );
