open Belt.Option;

[@bs.module "react-virtualized"] external _Table: ReasonReact.reactClass = "Table";

[@bs.deriving abstract]
type _jsProps = {
    [@bs.optional] className: string,
    headerHeight: int,
    height: int,
    [@bs.optional] onRowClick: Js.Json.t => unit,
    [@bs.optional] onRowDoubleClick: Js.Json.t => unit,
    [@bs.optional] onRowMouseOut: Js.Json.t => unit,
    [@bs.optional] onRowMouseOver: Js.Json.t => unit,
    [@bs.optional] onRowRightClick: Js.Json.t => unit,
    [@bs.optional] rowClassName: Js.Json.t => string,
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

let make =
    (~height, ~width, ~headerHeight, ~rowCount, ~rowHeight, ~rowGetter, ~rowClassName=?,
        ~onRowClick=?, ~onRowDoubleClick=?, ~onRowMouseOut=?, ~onRowMouseOver=?,
        ~onRowRightClick=?, ~className=?, children)
=>
    ReasonReact.wrapJsForReason(
        ~reactClass=_Table,
        ~props=_jsProps(
            ~className?,
            ~headerHeight,
            ~height,
            ~onRowClick=?map(onRowClick, _mouseEvent),
            ~onRowDoubleClick=?map(onRowDoubleClick, _mouseEvent),
            ~onRowMouseOut=?map(onRowMouseOut, _mouseEvent),
            ~onRowMouseOver=?map(onRowMouseOver, _mouseEvent),
            ~onRowRightClick=?map(onRowRightClick, _mouseEvent),
            ~rowClassName=?map(rowClassName, _makeRowCallback),
            ~rowCount,
            ~rowGetter=_makeRowCallback(rowGetter),
            ~rowHeight,
            ~width
        ),
        children,
    );
