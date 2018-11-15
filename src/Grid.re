[@bs.module "react-virtualized"] external _Grid: ReasonReact.reactClass = "Grid";

[@bs.deriving abstract]
type _jsProps = {
    columnCount: int,
    columnWidth: int => int,
    rowCount: int,
    rowHeight: int,

    height: int,
    width: int,

    cellRenderer: Js.Json.t => ReasonReact.reactElement
};

[@decco]
type cellInfo = {
    columnIndex: int,
    isScrolling: bool,
    isVisible: bool,
    key: string,
    rowIndex: int,
    style: [@decco.codec Decco.Codecs.magic] ReactDOMRe.style
};

[@bs.val "Object.assign"]
external _objAssign : Js.Dict.t(_) => ReactDOMRe.style => ReactDOMRe.style = "";

let _cellRendererWrapper = (cellRenderer, json) => {
    let { style } as cellInfo =
        cellInfo_decode(json)
        |> ResultEx.getExn;

    cellRenderer({
        ...cellInfo,
        style: _objAssign(Js.Dict.empty(), style)
    });
};

let make =
    (~height, ~width, ~columnCount, ~columnWidth, ~rowCount, ~rowHeight,
        ~cellRenderer, children)
    =>
        ReasonReact.wrapJsForReason(
          ~reactClass=_Grid,
          ~props=_jsProps(
              ~height, ~width, ~columnCount,
              ~columnWidth, ~rowCount, ~rowHeight,
              ~cellRenderer=_cellRendererWrapper(cellRenderer)
          ),
          children,
        );
