open Belt.Option;

[@bs.module "react-virtualized"] external _Table: ReasonReact.reactClass = "Table";

[@bs.deriving abstract]
type _jsProps = {
    headerHeight: int,
    height: int,
    onRowClick: Js.nullable(Js.Json.t => unit),
    onRowDoubleClick: Js.nullable(Js.Json.t => unit),
    onRowMouseOut: Js.nullable(Js.Json.t => unit),
    onRowMouseOver: Js.nullable(Js.Json.t => unit),
    onRowRightClick: Js.nullable(Js.Json.t => unit),
    rowClassName: Js.nullable(Js.Json.t => string),
    rowCount: int,
    rowGetter: Js.Json.t => Js.Dict.t(string),
    rowHeight: int,
    width: int,
};

[@decco] type rowIndex = { index: int };

module Event = {
    [@decco]
    type t = {
        event: [@decco.codec Decco.Codecs.magic] ReactEvent.Mouse.t,
        index: int,
        rowData: Js.Json.t
    };
};

let _makeRowCallback = (callback, json) =>
    rowIndex_decode(json)
    |> ResultEx.getExn
    |> callback;

let _mouseEvent = (callback, json) =>
    Event.t_decode(json)
    |> ResultEx.getExn
    |> callback;

let _nul = Js.Nullable.fromOption;

let make =
    (~height, ~width, ~headerHeight, ~rowCount, ~rowHeight, ~rowGetter, ~rowClassName=?,
        ~onRowClick=?, ~onRowDoubleClick=?, ~onRowMouseOut=?, ~onRowMouseOver=?,
        ~onRowRightClick=?, children)
=>
    ReasonReact.wrapJsForReason(
        ~reactClass=_Table,
        ~props=_jsProps(
            ~headerHeight,
            ~height,
            ~onRowClick=map(onRowClick, _mouseEvent) |> _nul,
            ~onRowDoubleClick=map(onRowDoubleClick, _mouseEvent) |> _nul,
            ~onRowMouseOut=map(onRowMouseOut, _mouseEvent) |> _nul,
            ~onRowMouseOver=map(onRowMouseOver, _mouseEvent) |> _nul,
            ~onRowRightClick=map(onRowRightClick, _mouseEvent) |> _nul,
            ~rowClassName=map(rowClassName, _makeRowCallback) |> _nul,
            ~rowCount,
            ~rowGetter=_makeRowCallback(rowGetter),
            ~rowHeight,
            ~width
        ),
        children,
    );
