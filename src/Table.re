[@bs.module "react-virtualized"] external _Table: ReasonReact.reactClass = "Table";

[@bs.deriving abstract]
type _jsProps = {
    headerHeight: int,
    height: int,
    rowCount: int,
    rowHeight: int,
    width: int,
    rowGetter: Js.Json.t => Js.Dict.t(string)
};

[@decco] type rowIndex = { index: int };

let _makeRowGetter = (rowGetter, json) =>
    rowIndex_decode(json)
    |> ResultEx.getExn
    |> rowGetter;

let make = (~height, ~width, ~headerHeight, ~rowCount, ~rowHeight, ~rowGetter, children)
=>
    ReasonReact.wrapJsForReason(
        ~reactClass=_Table,
        ~props=_jsProps(
            ~height, ~width, ~headerHeight, ~rowCount, ~rowHeight,
            ~rowGetter=_makeRowGetter(rowGetter)
        ),
        children,
    );
