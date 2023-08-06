SELECT
  query_name,
  ROUND(AVG(rating / position), 2) AS quality,
  ROUND(
    (
      SELECT COUNT(rating)
      FROM queries AS subquery
      WHERE subquery.query_name = queries.query_name
      AND rating < 3
    ) * 100 / COUNT(rating),
    2
  ) AS poor_query_percentage
FROM
  queries
GROUP BY
  query_name;
