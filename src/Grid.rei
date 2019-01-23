[@decco]
type cellInfo = {
    columnIndex: int,
    isScrolling: bool,
    isVisible: bool,
    key: string,
    rowIndex: int,
    style: ReactDOMRe.style,
};

let make:
    (~height: int, ~width: int, ~columnCount: int, ~columnWidth: int => int,
    ~rowCount: int, ~rowHeight: int,
    ~cellRenderer: cellInfo => ReasonReact.reactElement, 'a) =>
    ReasonReact.component(ReasonReact.stateless, ReasonReact.noRetainedProps,
        ReasonReact.actionless);
