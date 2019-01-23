[@bs.module "react-virtualized"] external _Column: ReasonReact.reactClass = "Column";

[@bs.deriving abstract]
type jsProps = {
    dataKey: string,
    width: int,
    label: Js.nullable(string),
    flexGrow: Js.nullable(int),
    flexShrink: Js.nullable(int),
};

let make = (~label=?, ~flexGrow=?, ~flexShrink=?, ~dataKey, ~width, children) =>
    ReasonReact.wrapJsForReason(
        ~reactClass=_Column,
        ~props=jsProps(
            ~label=Js.Nullable.fromOption(label),
            ~flexGrow=Js.Nullable.fromOption(flexGrow),
            ~flexShrink=Js.Nullable.fromOption(flexShrink),
            ~dataKey, ~width
        ),
        children,
    );
