open Belt.Option;

[@bs.module "react-virtualized"] external _Table: ReasonReact.reactClass = "Table";

[@bs.deriving abstract]
type jsProps = {
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

let makeRowCallback = (callback, json) =>
    rowIndex_decode(json)
    |> Belt.Result.getExn
    |> callback;

let mouseEvent = (callback, json) =>
    Event.t_decode(json)
    |> Belt.Result.getExn
    |> callback;

let make =
    (~height, ~width, ~headerHeight, ~rowCount, ~rowHeight, ~rowGetter, ~rowClassName=?,
        ~onRowClick=?, ~onRowDoubleClick=?, ~onRowMouseOut=?, ~onRowMouseOver=?,
        ~onRowRightClick=?, ~className=?, children) =>
{
    let props: jsProps = jsProps(
        ~className?,
        ~headerHeight,
        ~height,
        ~onRowClick=?map(onRowClick, mouseEvent),
        ~onRowDoubleClick=?map(onRowDoubleClick, mouseEvent),
        ~onRowMouseOut=?map(onRowMouseOut, mouseEvent),
        ~onRowMouseOver=?map(onRowMouseOver, mouseEvent),
        ~onRowRightClick=?map(onRowRightClick, mouseEvent),
        ~rowClassName=?map(rowClassName, makeRowCallback),
        ~rowCount,
        ~rowGetter=makeRowCallback(rowGetter),
        ~rowHeight,
        ~width,
        ()
    );

    ReasonReact.wrapJsForReason(
        ~reactClass=_Table,
        ~props,
        children,
    );
};
